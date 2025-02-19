# $ python python/translate.py example/qhexedit.pro

# This is a dirty hack that may work in this project but not in other projects

import asyncio, sys, re, os, shutil

try:
    from googletrans import Translator
except:
    print("Error: you may want to install googletrans '$ pip install googletrans'")
    exit(1)

class Translate:
    def __init__(self, pro_file):
        self._dir_path = os.path.dirname(os.path.realpath(pro_file))
        self._translator = Translator()
        
        with open(pro_file) as f:
            splits = re.split(' |\n|=', f.read())
        
        self._ts_files = []
        for split in splits:
            if len(split) > 3:
                if ".ts" == split[-3:]:
                    ts_path = os.path.join(self._dir_path, split)
                    with open(ts_path) as f:
                        content =  f.read()
                        todo = content.count('<translation type="unfinished"></translation>')
                        if todo > 0:
                            self._ts_files.append(ts_path)

    async def runner(self):
        tasks = []

        for ts_path in self._ts_files:
            task = asyncio.create_task(self._translate_file(ts_path))
            tasks.append(task)

        await asyncio.gather(*tasks)
        print()

    async def _translate_file(self, ts_path):
        file_name = os.path.basename(ts_path)
        print(f"Translating '{file_name}'")
        target_lang = ts_path.split('.')[0].split('_')[1]
        ts_write_path = ts_path + '~'

        with open(ts_path) as f:
            content =  f.read()

        with open(ts_write_path, 'wt') as fw:
            for frag in content.split("</translation>"):
                if "source>" in frag:
                    if frag[-31:] == '<translation type="unfinished">':
                        splits = frag.split('source>')
                        to_translate = splits[1][:-2]
                        translated = await self._translate_frag(to_translate, target_lang)
                        frag = frag[:-31] + "<translation>" + translated
                        print('.', end='', flush=True)
                    frag += "</translation>"
                fw.write(frag)

        shutil.move(ts_write_path, ts_path)

    async def _translate_frag(self, to_translate, target_lang):
        s = to_translate.replace("&quot;", "\"").replace("&apos;", "\'").replace("&lt;",   "<") \
            .replace("&gt;",   ">").replace("&amp;",  "\&").replace("&",      "")

        result = await self._translator.translate(s, src='en', dest=target_lang)
        return result.text

translate = Translate(sys.argv[1])
asyncio.run(translate.runner())

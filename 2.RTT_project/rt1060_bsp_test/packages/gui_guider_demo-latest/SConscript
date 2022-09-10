import rtconfig

from building import *

cwd = GetCurrentDir()
CPPPATH = [cwd, str(Dir('#'))]

include_path = [ cwd,
    os.path.join(cwd,"custom"),
    os.path.join(cwd,"generated"),
    os.path.join(cwd,"generated/guider_customer_fonts"),
    os.path.join(cwd,"generated/guider_fonts"),
    os.path.join(cwd,"generated/images")
]

src = Glob('*.c');

if GetDepend(['PKG_USING_GUI_GUIDER_DEMO']):
    src += Glob('custom/*.c')
    src += Glob('generated/*.c')
    src += Glob('generated/guider_customer_fonts/*.c')
    src += Glob('generated/guider_fonts/*.c')
    src += Glob('generated/images/*.c')

group = DefineGroup('GUI-Guider-demo', src, depend = ['PKG_USING_GUI_GUIDER_DEMO'], CPPPATH = include_path)

Return('group')

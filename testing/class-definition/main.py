import wx

if wx.VERSION >= (2, 5):
    class Foo:
        def __init__(self):
            self.x = 5
else:
    class Foo:
        def __init__(self):
            self.x = 7

f = Foo()
print f.x
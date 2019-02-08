from mod1.add_method import Foo
from mod1.add_method import Bar

def main():
    foo = Foo()
    print(foo.get_x())
    print(foo.get_y())

    bar = Bar()
    print(bar.get_x())
    print(bar.get_y())

main()

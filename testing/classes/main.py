from add_method import Foo

def ggg(self):
    return self.y

def main():
    foo = Foo()
    
    print(foo.get_x())
    print(foo.get_y())

main()

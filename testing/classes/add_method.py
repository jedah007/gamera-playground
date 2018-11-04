import comp

class Foo:
    def __init__(self):
        if not hasattr(Foo, 'get_y'):
            comp.add_method(Foo)
        self.x = 5
        self.y = 3
    
    def get_x(self):
        return self.x

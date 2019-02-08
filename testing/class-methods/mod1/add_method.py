import comp

class Foo:
    def __init__(self):
        if not hasattr(Foo, 'get_y'):
            comp.add_method(Foo)
        self.x = 5
        self.y = 3
    
    def get_x(self):
        return self.x

class Bar:
    def __init__(self):
        self.x = 1
        self.y = 2
    
    def get_x(self):
        return self.x

class XYZ: 
    def __init__(self):
        self.x = 7
        self.y = 9

    def get_x(self):
        return self.x

    def get_y(self):
        return self.y
    
comp.add_method(Bar)
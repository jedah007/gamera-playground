def add_method(clazz):
    def get_y(self):
        return self.y
    clazz.get_y = get_y
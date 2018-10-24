from gamera.core import *
init_gamera()
from gamera.plugins.png_support import load_PNG

img = load_image("fb.png")
result = img.fourier_broken()
print result

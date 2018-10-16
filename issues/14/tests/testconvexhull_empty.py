from gamera.core import *
init_gamera()
from gamera.plugins.geometry import convex_hull_from_points

# TODO
img = Image((0,0), (0,4), ONEBIT)
img.fill(1)
p = img.contour_pavlidis()
print p
hull = convex_hull_from_points(p)

from gamera.core import *
from gamera import knn
init_gamera()

cknn = knn.kNNNonInteractive(database="issue.xml", features=["fourier_broken"])

#!/bin/bash

if [[ $# -ne 3 ]]; then
    echo "Need environment name, conda home and gamera home"
    exit 1
fi

ENV=$1
CONDA=$2
GAMERA=$3

source activate $ENV
python env.py

cd $GAMERA
#git clean -f

python setup.py build && sudo python setup.py install

ENV_PACKAGES=$CONDA/envs/$ENV/lib/python2.7/site-packages
cd $ENV_PACKAGES

rm gamera*

LOCAL_PACKAGES=/usr/local/lib/python2.7/dist-packages
ln -s $LOCAL_PACKAGES/gamera
ln -s $LOCAL_PACKAGES/gamera-3.4.3.egg-info

source deactivate

#!/bin/bash

if [[ $# -ne 3 ]]; then
    echo "Need environment name, conda home and gamera home"
    exit 1
fi

ENV=$1
CONDA=$2
GAMERA=$3

cd $GAMERA
git clean -f

source activate $ENV
python setup.py build && sudo python setup.py install

ENV_PACKAGES=$CONDA/envs/$ENV/lib/python2.7/site-packages
rm -r $ENV_PACKAGES/gamera*

sudo cp -R /usr/local/lib/python2.7/dist-packages/gamera* $ENV_PACKAGES
sudo chown -R $USER:$USER $ENV_PACKAGES/gamera*

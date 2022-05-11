# pybind-tutorial
## Overview
- This repository provides simple examples to understand the overall python-native structure when using pybind11.
- The example codes include a simple addition and image loading/saving using native OpenCV library.

## Instructions
- Clone this repository including pybind11.
```
git clone --recursive https://github.com/MistyNight/pybind-tutorial.git
cd pybind-tutorial
```
- Create a virtual environment and install OpenCV.
```
conda create -n pybind-test
conda activate pybind-test
conda install -c conda-forge opencv
```
- Install a pybind test module using setup.py.
```
pip install -e .
```
- Check the test module.
```
cd test
python test_add.py
python test_image.py
```

import pybind_test as pt

if __name__ == '__main__':
    print('{0} + {1} = {2}'.format(1, 2, pt.add(1, 2)))
# MinManhattan

Minimize Manhattan distance of points.

Manhattan distance:

<img src="https://latex.codecogs.com/gif.latex?d(i,j)&space;=&space;\left&space;|x_1&space;-&space;x_2&space;\right&space;|&space;&plus;&space;\left&space;|&space;y_1&space;-&space;y_2&space;\right&space;|" title="d(i,j) = \left |x_1 - x_2 \right | + \left | y_1 - y_2 \right |" />

Minimize distance:

<img src="https://latex.codecogs.com/png.latex?\min_{x,y}&space;\sum_{i}&space;{&space;\left&space;|x_i&space;-&space;x&space;\right&space;|&space;&plus;&space;\left&space;|&space;y_i&space;-&space;y&space;\right&space;|}" title="\min_{x,y} \sum_{i} { \left |x_i - x \right | + \left | y_i - y \right |}" />

## request

Matrix library:
[`Eigen`](http://eigen.tuxfamily.org/index.php?title=Main_Page "eigen")

Nonlinear solver:
[`Ceres Solver`](http://ceres-solver.org/ "Ceres Solver")

## build 

```
mkdir build
cd build 
cmake ..
make 
```

## run

In build folder:

```
./manhattan_test
```

## result

<p align="center">
  <img src="figures/dst.jpg">
</p>

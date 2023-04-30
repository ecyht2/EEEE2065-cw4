# EEEE2065-cw4
A C++ script that computes if a given complex number is within the Mandelbrot set.

The Rust implementation of the script can be found [here](https://github.com/ecyht2/mandelbrot-set-rs).

## Building

### Requirements
`Cmake` Cmake is used to compile the program. You can download cmake [here](https://cmake.org/download/).

### Compiling

``` sh
git clone https://github.com/ecyht2/EEEE2065-cw4.git
cd EEEE2065-cw4/
cmake . && cmake --build .
```

## Usage

After compilation a directory `bin/` should be created in the repository. To run it, run the command.

``` sh
bin/mandelbrot-set
```

## Documentation

Documentation of the coursework can be found in the project [GitHub pages](https://ecyht2.github.io/EEEE2065-cw4/).

## TODO
* [ ] Improved Mandelbrot set algorigthm
* [ ] Setters for Mandelbrot set iterations and display characters
* [ ] Getters for Complex polar form
* [ ] Support for degrees for complex polar form
* [ ] Add support for argv

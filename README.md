# Julia Set Fractal Renderer

![fractal rendering screenshot](./screenshot.png)

Renders the julia set using a very simple shader program.

If you're interested in how to do this, all the relevant work is done by the
`float julia(vec2 uv, float time)` function in
[`./assets/fractal.frag`](./assets/fractal.frag).

## Compiling and running
```bash
mkdir build && cd build
cmake ..
make && ./fractals
```

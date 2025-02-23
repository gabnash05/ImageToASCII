# ImageToASCII
A simple converter that converts **Images** into **ASCII** text. It can handle:

- **JPEG** (`.jpg`, `.jpeg`)

- **PNG** (`.png`)

- **BMP** (`.bmp`)

- **GIF** (`.gif`) *(only the first frame is loaded; no animation support)*

- **TGA** (`.tga`)

- **PSD** (`.psd`) *(only non-multilayered images)*

- **PIC** (`.pic`) *(Softimage PIC format)*

- **PNM** (`.ppm`, `.pgm`) *(Portable Anymap format, ASCII & binary variants supported)*

<br></br>

## Prerequisites
Before you begin, ensure you have the following installed on your system:

- **CMake** (version 3.10 or later)
- **Ninja** Build System
- A **C++ Compiler** (e.g., g++, Clang)

<br></br>

## Installation & Build Instructions
1. **Clone the repository**
    ```
    git clone https://github.com/your-username/ImageToASCII.git
    cd ImageToASCII
    ```

2. **Create a build directory and navigate into it**
    ```
    mkdir build
    cd build
    ```
3. **Generate build files using CMake**
    ```
    cmake -G "Ninja" ..
    ```
4. **Compile the project**
    ```
    ninja
    ```

<br></br>

## Usage
To convert an image to ASCII, run:
```
./imageToASCII <image_path> <compression_index> <character_set>
```

- `<image_path>`: Path to the image file (e.g., `../assets/image2.jpg`)

- `<compression_index>`: An integer from **1 to 10**, where **1** has the least compression and **10** has the most.

- `<character_set>`:
    - `1` → Uses simple ASCII characters (`@#%*+=-:. `)
    - `2` → Uses detailed ASCII characters (`$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft...`)

<br></br>

## Example
```
./imageToASCII ../assets/image2.jpg 2 2
```

<br></br>

## Output
The converted ASCII art will be saved in:
```
../output/output.txt
```
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// greyscale ascii conversion values from https://www.geeksforgeeks.org/converting-image-ascii-image-python/
const char* ASCII_CHARS_1 = "@#%*+=-:. ";
const char* ASCII_CHARS_2 = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~i!lI;:,\"^`\". ";

using namespace std;

int main(int argc, char** argv) {
  int width, height, channels, compressionIndex, characterSet;
  char *inputFilename;

  if (argc < 4) {
    cerr << "Usage: " << argv[0] << " <input filename> <compression index> <character set>" << endl;
    return 1;
  }

  inputFilename = argv[1];
  compressionIndex = atoi(argv[2]);
  characterSet = atoi(argv[3]);

  if (compressionIndex > 10) {
    cerr << "Compression index must be between 1 and 10" << endl;
    return 1;
  }

  // Input Image
  unsigned char *img = stbi_load(inputFilename, &width, &height, &channels, 0);
  if (img == NULL) {
    cerr << "Failed to load image" << endl;
    return 1;
  }

  // Output .txt file
  ofstream file("../output/output.txt", ios::trunc);
  if (!file.is_open()) {
    cerr << "Error: Could not create the file." << endl;
  }

  std::cout << "Conversion starting...." << endl;

  int pixelY = 2 * compressionIndex;
  int pixelX = compressionIndex;

  for (int y = 0; y < height; y += pixelY) {
    for (int x = 0; x < width; x += pixelX) {
      float greyscaleTotal = 0;
      int count = 0;

      // 3x3 grid
      for (int dy = 0; dy < pixelY && (y + dy) < height; dy++) {
        for (int dx = 0; dx < pixelX && (x + dx) < width; dx++) {
          int index = ((y + dy) * width + (x + dx)) * channels;

          unsigned char rawR = img[index];
          unsigned char rawG = img[index + 1];
          unsigned char rawB = img[index + 2];

          float r = rawR / 255.0f;
          float g = rawG / 255.0f;
          float b = rawB / 255.0f;

          // Convert to greyscale formula from https://stackoverflow.com/questions/17615963/standard-rgb-to-grayscale-conversion
          float greyscale = 0.2126f * r + 0.7152f * g + 0.0722f * b;
          greyscaleTotal += greyscale;
          count++;
        }
      }

      float avgGreyscale = greyscaleTotal / count;

      // Character set
      if (characterSet == 1) {
        int asciiIndex = static_cast<int>(avgGreyscale * (strlen(ASCII_CHARS_1) - 1));
        file << ASCII_CHARS_1[asciiIndex];
      } else {
        int asciiIndex = static_cast<int>(avgGreyscale * (strlen(ASCII_CHARS_2) - 1));
        file << ASCII_CHARS_2[asciiIndex];
      }
    }
    file << endl;
  }

  stbi_image_free(img);
  file.close();
  cout << "Conversion Finished" << endl;

  return 0;
}
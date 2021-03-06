#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <fstream>
#include "vec3.h"
class Image {
    public:
        int width; //横幅
        int height; //縦幅
        Vec3* data;

        Image(int _width, int _height) {
            width = _width;
            height = _height;
            //配列をメモリ上に確保する
            data = new Vec3[width*height];
        };
        ~Image() {
            //確保したメモリを解放する
            delete[] data;
        };

        //(i, j)のRGBを返す
        Vec3 getPixel(int i, int j) const {
            return data[width*i + j];
        };
        //(i, j)にRGBを書き込む
        void setPixel(int i, int j, const Vec3& color) {
            data[width*i + j] = color;
        };

        //PPM画像を出力する
        void ppm_output() const {
            //ファイルを開く
            std::ofstream file("output.ppm");
            
            //PPMのフォーマットに則って出力する
            file << "P3" << std::endl;
            file << width << " " << height << std::endl;
            file << "255" << std::endl;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    Vec3 color = 255*this->getPixel(j, i);
                    int r = (int)color.x;
                    int g = (int)color.y;
                    int b = (int)color.z;
                    file << r << " " << g << " " << b << std::endl;
                }
            }
            //ファイルを閉じる
            file.close();
        };
};
#endif

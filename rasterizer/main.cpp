/*
\ （颜色数据）+
\ 顶点数据->顶点着色器（Model平移旋转，View平移旋转缩放, Projection透视投影得到齐次坐标->二维坐标）
\        ->[细分控制着色器]->[细分计算着色器]->[几何着色器]
\        ->图元装配(将点还原出网格结构，[在视椎体中进行裁剪，切分成三角形、可能需要颜色插值])
\        ->裁剪（[近平面裁剪，透视除法, 投影到裁剪空间？]）
\        ->光栅化（裁剪（颜色插值），Top-Left、Scanline）
\        ->片元着色器(Color)
\        ->[深度检测、模板检测、混合]
\        ->draw
\
\      透视投影->裁剪->透视除法
\         在透视除法前进行裁剪是因为此时可以进行线性插值
\         裁剪的范围是透视除法后确定的规范化立方体
\       透视投影后的是齐次空间
\ 1.math library
\ 
*/





#include <vector>
#include <array>
using namespace std;


class Point3 {};
class Point2 {};


int main() {
	
	vector<Point3> Vetices{ };


}


class Matrix {
public:
	Point3 operator*(Point3 p) { return Point3(); }
	Matrix operator*(Matrix m) { return Matrix();  }
};

Point2 project(const Point3 &p) { return Point2(); }


vector<Point2> VetexShader(vector<Point3> &vetices){
	Matrix Model, View, Projection;
	
	vector<Point2> positions;
	for (auto &v : vetices) {
		positions.push_back(project(Projection * View * Model * v));
	}
		
	return std::move(positions);
}


class Triangle {
public:
	Triangle(Point2, Point2, Point2) {}
	Point2 p1;
	Point2 p2;
	Point2 p3;
};


vector<Triangle> assembly(vector<Point2> &positions) {
	vector<Triangle> triangles;
	for (size_t i = 0; i < positions.size(); ++i) {
		auto p1 = positions[i++];
		auto p2 = positions[i++];
		auto p3 = positions[i];
		// i point to 3rd
		// 判断逆时针调整点顺序

		triangles.push_back(Triangle(p1, p2, p3));
	}
	
	return std::move(triangles);
}


bool outOfRange(const Point2 &p) {}


// Viewport
// 二维裁剪算法, 颜色插值
vector<Triangle> clip(vector<Triangle> &triangles) {
	vector <Triangle> scrnCrdnt;
	
	for (size_t i = 0; i < triangles.size(); ++i) {
		// 超出viewport裁剪 并产生新的三角形
	}

	return std::move(scrnCrdnt);
}


struct Color {
	unsigned char R;
	unsigned char G;
	unsigned char B;
};


struct Frag {
	Color color;
	float z;
	Frag *next;
};


const constexpr size_t Width = 256, Height = 256;
using FragPointer = Frag*;
using FragPtrMap = array<array<FragPointer, Width>, Height>;
FragPtrMap Rasterize(vector<Triangle> triangles) {
	FragPtrMap fragMap;  // nullptr for empty
	
	// 对每一个三角形进行一次扫描线 还是 对多边形进行一次扫描线
	for (auto &t : triangles) {
		// Scan line
	}

	// 相同光栅中的片元存放在一个链表中

	return std::move(fragMap);
} 


FragPtrMap fragShader(FragPtrMap &fragMap) {
	return fragMap;
}


using ColorLine = array<Color, Width>;
using ColorMap = array<ColorLine, Height>;
ColorMap ZTest(FragPtrMap &fragMap) {
	ColorMap colorMap;
	for (size_t i = 0; i < fragMap.size(); ++i) {
		ColorLine line;
		for (size_t j = 0; j < fragMap[i].size(); ++j) {
			// find the ptr to a fragment with the largest Z to replace *fptr
		}
		// colorMap[i] = ?
	}

	return std::move(colorMap);
}

void draw(const ColorMap &colorMap) {

}




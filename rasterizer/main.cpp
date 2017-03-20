///*
//\ ����ɫ���ݣ�+
//\ ��������->������ɫ����Modelƽ����ת��Viewƽ����ת����, Projection͸��ͶӰ�õ��������->��ά���꣩
//\        ->[ϸ�ֿ�����ɫ��]->[ϸ�ּ�����ɫ��]->[������ɫ��]
//\        ->ͼԪװ��(���㻹ԭ������ṹ��[����׵���н��вü����зֳ������Ρ�������Ҫ��ɫ��ֵ])
//\        ->�ü���[��ƽ��ü���͸�ӳ���, ͶӰ���ü��ռ䣿]��
//\        ->��դ�����ü�����ɫ��ֵ����Top-Left��Scanline��
//\        ->ƬԪ��ɫ��(Color)
//\        ->[��ȼ�⡢ģ���⡢���]
//\        ->draw
//\
//\      ͸��ͶӰ->�ü�->͸�ӳ���
//\         ��͸�ӳ���ǰ���вü�����Ϊ��ʱ���Խ������Բ�ֵ
//\         �ü��ķ�Χ��͸�ӳ�����ȷ���Ĺ淶��������
//\       ͸��ͶӰ�������οռ�
//\ 1.math library
//\ 
//*/
//
//
//
//
//
//#include <vector>
//#include <array>
//#include "math.h"
//using namespace std;
//
//
//
////int main() {
////	
////	vector<Point3> Vetices{ };
////
////
////}
//
//Mat4 Model = array<Vec4, 4>{
//	Vec4{ 1.0f, 0.0f, 0.0f, 0.0f },
//	Vec4{ 0.0f, 1.0f, 0.0f, 0.0f },
//	Vec4{ 0.0f, 0.0f, 1.0f, 0.0f },
//	Vec4{ 0.0f, 0.0f, 0.0f, 1.0f }
//};
//
//Mat4 View = array<Vec4, 4>{
//	Vec4{ 1.0f, 0.0f, 0.0f, 0.0f },
//	Vec4{ 0.0f, 1.0f, 0.0f, 0.0f },
//	Vec4{ 0.0f, 0.0f, 1.0f, 0.0f },
//	Vec4{ 0.0f, 0.0f, 0.0f, 1.0f }
//};
//
//Mat4 Projection = array<Vec4, 4>{
//	Vec4{ 1.0f, 1.0f, 1.0f, 1.0f },
//	Vec4{ 1.0f, 1.0f, 1.0f, 1.0f },
//	Vec4{ 1.0f, 1.0f, 1.0f, 1.0f },
//	Vec4{ 1.0f, 1.0f, 1.0f, 1.0f }
//};
//
//
//// �۾�����(�۲�����ϵ������ϵ)->�ü�����->�淶�����豸����(����ϵ)
//Mat4 pespective(float nearWidth, float nearHeight, float zNear, float zFar) {
//	return Mat4{ 
//		zNear / (nearWidth / 2.0f),  0.0f,                         0.0f,                              0.0f,
//		0.0f,                        zNear / (nearHeight / 2.0f),  0.0f,                              0.0f, 
//	    0.0f,                        0.0f,                         -(zFar + zNear) / (zFar - zNear),  2 * zFar * zNear / (zFar - zNear),
//		0.0f,                        0.0f,                         -1.0f,                             0.0f
//	};
//}
//
//
//Point2 project(const Vec4 &p) { return Point2(); }
//
//
//vector<Point2> VetexShader(vector<Point3> &vetices){
//	vector<Point2> positions;
//	for (auto &v : vetices) {
//		positions.push_back(project(Vec4(v, 1.0f) * Model* View * Projection));
//	}
//		
//	return std::move(positions);
//}
//
//
//class Triangle {
//public:
//	Triangle(Point2, Point2, Point2) {}
//	Point2 p1;
//	Point2 p2;
//	Point2 p3;
//};
//
//
//vector<Triangle> assembly(vector<Point2> &positions) {
//	vector<Triangle> triangles;
//	for (size_t i = 0; i < positions.size(); ++i) {
//		auto p1 = positions[i++];
//		auto p2 = positions[i++];
//		auto p3 = positions[i];
//		// i point to 3rd
//		// �ж���ʱ�������˳��
//
//		triangles.push_back(Triangle(p1, p2, p3));
//	}
//	
//	return std::move(triangles);
//}
//
//
//bool outOfRange(const Point2 &p) { return true; }
//
//
//// Viewport
//// ��ά�ü��㷨, ��ɫ��ֵ
//vector<Triangle> clip(vector<Triangle> &triangles) {
//	vector <Triangle> scrnCrdnt;
//	
//	for (size_t i = 0; i < triangles.size(); ++i) {
//		// ����viewport�ü� �������µ�������
//	}
//
//	return std::move(scrnCrdnt);
//}
//
//
//struct Color {
//	unsigned char R;
//	unsigned char G;
//	unsigned char B;
//};
//
//
//struct Frag {
//	Color color;
//	float z;
//	Frag *next;
//};
//
//
//const constexpr size_t Width = 256, Height = 256;
//using FragPointer = Frag*;
//using FragPtrMap = array<array<FragPointer, Width>, Height>;
//FragPtrMap Rasterize(vector<Triangle> triangles) {
//	FragPtrMap fragMap;  // nullptr for empty
//	
//	// ��ÿһ�������ν���һ��ɨ���� ���� �Զ���ν���һ��ɨ����
//	for (auto &t : triangles) {
//		// Scan line
//	}
//
//	// ��ͬ��դ�е�ƬԪ�����һ��������
//
//	return std::move(fragMap);
//} 
//
//
//FragPtrMap fragShader(FragPtrMap &fragMap) {
//	return fragMap;
//}
//
//
//using ColorLine = array<Color, Width>;
//using ColorMap = array<ColorLine, Height>;
//ColorMap ZTest(FragPtrMap &fragMap) {
//	ColorMap colorMap;
//	for (size_t i = 0; i < fragMap.size(); ++i) {
//		ColorLine line;
//		for (size_t j = 0; j < fragMap[i].size(); ++j) {
//			// find the ptr to a fragment with the largest Z to replace *fptr
//		}
//		// colorMap[i] = ?
//	}
//
//	return std::move(colorMap);
//}
//
//void draw(const ColorMap &colorMap) {
//
//}
//

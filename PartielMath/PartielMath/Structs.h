#ifndef STRUCT_H
#define STRUCT_H

enum Axis {
	X, Y, Z
};

struct Vertex
{
	float x;
	float y;
	float z;

	float nx;
	float ny;
	float nz;

	char value;
	void Rotate(float angle, Axis axis);
	//float ComputeIllumination(Light const& light) const;
};

#endif // !STRUCT_H


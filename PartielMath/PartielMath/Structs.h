#ifndef STRUCT_H
#define STRUCT_H

enum Axis {
	X, Y, Z
};

class Light;

struct Vertex
{
	float x;
	float y;
	float z;

	struct // normal
	{
		float x;
		float y;
		float z;
	} n;


	char value;
	void Rotate(float angle, Axis axis);
	float ComputeIllumination(Light const& light) const;
};

#endif // STRUCT_H


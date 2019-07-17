#include "Particle.hlsli"

static const uint vnum = 4;
static const float4 offset_array[vnum] =
{
	float4(+.5f, -.5f, 0, 0),
	float4(-.5f, -.5f, 0, 0),
	float4(+.5f, +.5f, 0, 0),
	float4(-.5f, +.5f, 0, 0),
};

[maxvertexcount(vnum)]
void main(
	point PS_INPUT input[1],
	inout TriangleStream<PS_INPUT> output
)
{
	for (uint i = 0; i < vnum; i++)
	{
		PS_INPUT element;
		element.Pos = input[0].Pos + offset_array[i] * 1.f;
		element.Pos = mul(element.Pos, matWorld);
		element.Pos = mul(element.Pos, matView);
		element.Pos = mul(element.Pos, matProj);

		//element.Tex = input[0].Tex + float2(offset_array[i].x, -offset_array[i].y) + float2(.5f, .5f);
		element.Tex = input[0].Tex - offset_array[i] + float2(.5f, .5f);
		output.Append(element);
	}
}
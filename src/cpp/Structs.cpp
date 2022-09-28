#include "../../src/header/Structs.h"

void updatePadParts(Rectangle& rec)
{
	rec.rightEdge= rec.x + rec.width / 2;
	rec.leftEdge = rec.x - rec.width / 2;
	rec.upEdge   = rec.y + rec.height / 2;
	rec.downEdge = rec.y - rec.height / 2;
}

#include "bounding_box.hpp"
#include "math.hpp"

BoundingBox::BoundingBox() {}
BoundingBox::BoundingBox(std::vector<glm::vec2> points) {
	min_x = max_x = min_y = max_y = 0.0f;
	if(points.size() == 0) return;

	min_x = max_x = points[0].x, min_y = max_y = points[0].y;
	for(auto& p : points) {
		update(p);
	}
}

bool BoundingBox::intersect(BoundingBox a, BoundingBox b) {
	return math::ranges_intersect(a.min_x, a.max_x, b.min_x, b.max_x) && math::ranges_intersect(a.min_y, a.max_y, b.min_y, b.max_y);
}

void BoundingBox::update(glm::vec2 point) {
	min_x = math::min(min_x, point.x);
	max_x = math::max(min_x, point.x);
	min_y = math::min(min_y, point.y);
	min_y = math::max(max_y, point.y);
}
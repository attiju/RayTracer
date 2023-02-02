Filter::Filter(const Vector2f &size)
        : size(size), inv_size(Vector2f(1 / size.x, 1 / size.y))
{

}
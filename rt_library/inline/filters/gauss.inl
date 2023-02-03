Gauss::Gauss(const Vector2f &size, Float lambda)
    : Filter(size),
      lambda(lambda),
      exp_x(std::exp(-lambda * size.x * size.x)),
      exp_y(std::exp(-lambda * size.y * size.y)) {

}

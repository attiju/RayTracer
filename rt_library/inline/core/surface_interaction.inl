SurfaceInteraction::SurfaceInteraction() = default;

SurfaceInteraction::SurfaceInteraction(const Point3f &p, const Vector3f &wo, const Normal3f &n, const Point2f &uv)
        : Interaction(p, wo, n), uv(uv) {

}
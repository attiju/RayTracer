Interaction::Interaction() = default;

Interaction::Interaction(const Point3f &p, const Vector3f &wo, const Normal3f &n)
        : p(p), wo(wo), n(n)
{

}

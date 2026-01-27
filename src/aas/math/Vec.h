// Vec.h  (minimal Vec<N> to replace current Vec2 / Vec3 structs)
/*
2D Vectors for those who bind speed and direction in one,
3D Vectors for the world of x, y, and z under the sun,
4D Vectors for Quaternions, who despise gimbal lock above all,
N-Dimensional Vectors for the Developer in his darkest room,
In the Land of Linking, where the Templates lie.

N Dimensions to rule them all, N Dimensions to find them,
N Dimensions to bring them all, and in the compiler bind them,
In the Land of Linking, where the Templates lie.
*/
#pragma once

#include <array>
#include <cstddef>
#include <cassert>
#include <cmath>

using Scalar = float;

template <std::size_t N>
struct Vec
{
    std::array<float, N> v{}; // zero-initialized

    // Constructors
    constexpr Vec() = default;

    // Vec<2>(x,y), Vec<3>(x,y,z) //Vec<4>(a+bi+cj+dK)
    template <typename... Ts>
    constexpr Vec(Ts... comps) : v{ static_cast<float>(comps)... }
    {
        static_assert(sizeof...(Ts) == N, "Vec<N> constructor requires exactly N components.");
    }

    // Indexing
    constexpr float& operator[](std::size_t i) noexcept
    {
        assert(i < N);
        return v[i];
    }

    constexpr float operator[](std::size_t i) const noexcept
    {
        assert(i < N);
        return v[i];
    }

    // Named component access (use these to avoid rewriting a lot of code)
    // Now with assets to make sure I dont do something stupid like
    // Ask for a dimenion that doesnt exist
    constexpr float& x() noexcept { static_assert(N >= 1); return v[0]; }
    constexpr float& y() noexcept { static_assert(N >= 2); return v[1]; }
    constexpr float& z() noexcept { static_assert(N >= 3); return v[2]; }

    constexpr float x() const noexcept { static_assert(N >= 1); return v[0]; }
    constexpr float y() const noexcept { static_assert(N >= 2); return v[1]; }
    constexpr float z() const noexcept { static_assert(N >= 3); return v[2]; }
};


template <std::size_t N>
constexpr Vec<N> operator+(Vec<N>& a, const Vec<N>& b) noexcept
{
    a += b;
    return a;
}

template <std::size_t N>
constexpr Vec<N>& operator+=(Vec<N>& a, const Vec<N>& b) noexcept
{
    Vec<N> result;
    for (std::size_t i = 0; i < N; ++i)
        a[i] += b[i];
    return result;
}

template <std::size_t N>
constexpr Vec<N> operator-(const Vec<N>& a, const Vec<N>& b) noexcept
{
    a -= b;
    return a;
}

template <std::size_t N>
constexpr Vec<N>& operator-=(Vec<N>& a, const Vec<N>& b) noexcept
{
    Vec<N> result;
    for (std::size_t i = 0; i < N; ++i)
        a[i] -= b[i];
    return result;
}

template <std::size_t N>
constexpr Vec<N> operator*(const Vec<N>& v, Scalar s) noexcept
{
    v *= s;
    return v;
}

template <std::size_t N>
constexpr Vec<N> operator*(Scalar s, const Vec<N>& v) noexcept
{
    v *= s;
    return v;
}

template <std::size_t N>
constexpr Vec<N>& operator*=(Vec<N>& v, Scalar s) noexcept
{
    Vec<N> result;
    for (std::size_t i = 0; i < N; ++i)
        v[i] *= s;
    return result;
}

template <std::size_t N>
constexpr float dot(const Vec<N>& a, const Vec<N>& b) noexcept
{
    float sum = 0.0f;
    for (std::size_t i = 0; i < N; ++i)
        sum += a[i] * b[i];
    return sum;
}

template <std::size_t N>
constexpr float lengthSq(const Vec<N>& v) noexcept
{
    return dot(v, v);
}

template <std::size_t N>
inline float length(const Vec<N>& v) noexcept
{
    return std::sqrt(lengthSq(v));
}

template <std::size_t N>
inline float normalize(const Vec<N>& v) noexcept
{

    float len = 0.0f;
    len = length(v);
    if (len > .0000001){
        for (std::size_t i = 0; i < N; ++i) 
            v[i] = v[i] / len;
    }

    return std::sqrt(lengthSq(v));
}

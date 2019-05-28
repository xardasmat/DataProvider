#pragma once

template <typename T>
class SingleDPView
{
public:
    SingleDPView(const T& t)
        :t(t)
    {}
    const T& get() const
    {
        return t;
    }
private:
    const T& t;
};

template <typename...Ts>
class DPView : public SingleDPView<Ts>...
{
public:
    DPView(const Ts...ts)
        : SingleDPView<Ts>(ts)...
    {}

    template <typename...Ts2>
    DPView(const DPView<Ts2...>& dp2)
        : SingleDPView<Ts>(dp2)...
    {}

    template <typename T, typename...Args>
    auto get(Args...args) const
    {
        const SingleDPView<T>& t = *this;
        return t.get()(std::forward<Args>(args)..., *this);
    }
};


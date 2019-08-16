class HashClass
{
public:
    size_t operator()(const vector<string> &x) const
    {
        unsigned long int hash_value = hash_fn(x[1]);
        return hash_value;
    }
};
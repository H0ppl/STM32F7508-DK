#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void enable_temperature_read(bool enable);

protected:
    ModelListener* modelListener;
private:
    int tickCounter{0};
    bool temp_read_enabled{false};

    int get_temperature();
};

#endif // MODEL_HPP

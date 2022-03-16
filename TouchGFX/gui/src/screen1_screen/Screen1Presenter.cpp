#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{
	model->enable_temperature_read(true);
}

void Screen1Presenter::deactivate()
{
	model->enable_temperature_read(false);
}

void Screen1Presenter::updateTemperature(int value)
{
	view.setInternalTemperature(value);
}

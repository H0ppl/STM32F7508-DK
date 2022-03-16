#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
    tickCounter++;
    if (((tickCounter % 20) == 0) && temp_read_enabled)
    {
      if (modelListener != nullptr)
      {
    	  modelListener->updateTemperature(get_temperature());
      }
    }

}

int Model::get_temperature()
{
	static int cnt = 0;
	return cnt++;
}

void Model::enable_temperature_read(bool enable)
{
	temp_read_enabled = enable;
}

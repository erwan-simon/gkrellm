#include <iostream>
#include <string>
#include "Infos.hpp"
#include "Core.hpp"
#include "User.hpp"

void	updateInfos(Infos &infos);

void	display(Infos &infos)
{
  updateInfos(infos);
  std::cout << "**************** NETWORK *******************" << std::endl;
  std::cout << "Up : " << infos._network.getUp() << std::endl;
  std::cout << "Down : " << infos._network.getDown() << std::endl << std::endl;

  std::cout << "**************** CORE *******************" << std::endl;
  std::cout << "CPUModel : " << infos._core.getCPUModel() << std::endl;
  std::cout << "coreNb : " << infos._core.getCoreNb() << std::endl;
  std::cout << "core 1 : " << infos._core.getCorePercent()[0] << std::endl;
  std::cout << "core 2 : " << infos._core.getCorePercent()[1] << std::endl;
  std::cout << "core 3 : " << infos._core.getCorePercent()[2] << std::endl;
  std::cout << "core 4 : " << infos._core.getCorePercent()[3] << std::endl;
  std::cout << "ram : " << infos._core.getRam()[0] << "/" << infos._core.getRam()[1] << std::endl;
  std::cout << "swap : " << infos._core.getSwap()[0] << "/" << infos._core.getSwap()[1] << std::endl;
  std::cout << "nbTasks : " << infos._core.getNbTasks() << std::endl << std::endl;

  std::cout << "**************** USER *******************" << std::endl;
  std::cout << "MachineName : " << infos._user.getMachineName() << std::endl;
  std::cout << "UserName : " << infos._user.getUserName() << std::endl;
  std::cout << "OS : " << infos._user.getOpSys() << std::endl;
  std::cout << "Kernel : " << infos._user.getKernel() << std::endl;
  std::cout << "date : " << infos._user.getDate() << std::endl;
  std::cout << "Time : " << infos._user.getTime() << std::endl << std::endl;

}

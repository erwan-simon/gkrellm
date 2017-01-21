//
// Core.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 13:15:51 2017 erwan
// Last update Sat Jan 21 17:12:54 2017 Pierre-Emmanuel Merlier
//

#ifndef CORE_HPP_
# define CORE_HPP_

#include <fstream>
#include <string>
#include <sys/sysinfo.h>

class		Core
{
public:
  Core();
  ~Core();
  Core&		operator=(Core const &other);

public:
  std::string	getCPUModel() const;
  int		getCoreNb() const;
  float		*getCorePercent() const;
  float		*getRam() const;
  float		*getSwap() const;
  int		*getTasksNb() const;
  float		*getLoadAvg() const;

  void		setCPUModel(std::string CPUModel);
  void		setCoreNb(int core);
  void		setCorePercent(float *corePercent);
  void		setRam(float *ram);
  void		setSwap(float *swap);
  void		setTasksNb(int *tasksNb);
  void		setLoadAvg(float *loadAvg);

  void		getLoadAvgFromFile();
  void		getCPUInfo();
  void		getRamInfo(struct sysinfo);
  void		getSwapInfo(struct sysinfo);
private:
  std::string	_CPUModel; // modele du processeur
  int		_coreNb; // nombre de core
  float		*_corePercent; // tableau contenant dans l'ordre des cores leur pourcentage d'utilisation
  float		*_ram; // tableau contenant le volume de ram utilise et le total
  float		*_swap; // tableau contenant le volume de mémoire swap utilise et le total
  int		*_tasksNb; // tableau avec : nb de tache total, nb de tache en veille, nb de tache en cours
  float		*_loadAvg; // tableau avec les trois valeurs du load average (charge processeur). cf. Wikipedia
};

std::string parsingCPU(const std::string, const std::string, const std::string);

#endif

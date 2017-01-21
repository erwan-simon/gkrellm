//
// Core.hpp for rush in /home/erwan/Code/teck/piscine/cpp_gkrellm
// 
// Made by erwan
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Jan 21 13:15:51 2017 erwan
// Last update Sat Jan 21 14:33:26 2017 erwan
//

#ifndef CORE_HPP_
# define CORE_HPP_

#include <string>

class		Core
{
public:
  Core();
  ~Core();
  Core&		operator=(Core const &other);

public:
  int		getCoreNb() const;
  float		*getCorePercent() const;
  float		*getRam() const;
  float		*getSwap() const;
  int		*getTasksNb() const;
  float		*getLoadAvg() const;
    
  void		setCoreNb(int core);
  void		setCorePercent(float *corePercent);
  void		setRam(float *ram);
  void		setSwap(float *swap);
  void		setTasksNb(int *tasksNb);
  void		setLoadAvg(float *loadAvg);
    
private:
  int		_coreNb; // nombre de core
  float		*_corePercent; // tableau contenant dans l'ordre le pourcentage d'utilisation des core
  float		*_ram; // tableau contenant le volume de ram utilisé et le total
  float		*_swap; // tableau contenant le volume de mémoire swap utilisé et le total
  int		*_tasksNb; // tableau avec : nb de tache total, nb de tache en veille, nb de tache en cours
  float		*_loadAvg; // tableau avec les trois valeurs du load average (charge processeur). cf. Wikipedia
};

#endif
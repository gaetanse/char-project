#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "librairies.h"

class pathfinding
{
    public:
        pathfinding();
        ~pathfinding();

        void debut(int dep,int ari,std::vector<int>v_){

            case_depart=dep;
            case_arrive=ari;
            case_depart_=dep;
            case_arrive_=0;
            for(int a=0;a<v_.size();a++){
                v_case_possible.push_back(v_.at(a));
                v_restant.push_back(v_.at(a));
            }

            trouve();

        }

        std::vector<int> pathOk(){return v_obt_qzdqdz;}

        void trouve(){

            v_obt.push_back(case_depart);

            std::cout << "----------------------------------------------------" << std::endl;

            int sizela=0;

            std::cout << case_depart << std::endl;

            for(int a=sizela;a<v_obt.size();a++){


                for(int b=0;b<v_case_possible.size();b++){
                    if(v_obt.at(a)-1==v_case_possible.at(b)){
                        v_test_nb_chemin.push_back(-1);
                      //  v_obt.erase(v_obt.begin()+a);
                      //  v_obt.push_back(v_restant.at(a)-1);
                        std::cout << v_obt.at(a)-1 << std::endl;
                        //v_obt.clear();
                        v_obt.push_back(v_obt.at(a)-1);
                        sizela++;
                        v_case_possible.erase(v_case_possible.begin()+b);

                        v_obt_qzdqdz.push_back(1);
                        break;
                    }
                    else if(v_obt.at(a)+1==v_case_possible.at(b)){
                        v_test_nb_chemin.push_back(1);
                       // v_obt.erase(v_obt.begin()+a);
                       // v_obt.push_back(v_restant.at(a)+1);
                        std::cout << v_obt.at(a)+1 << std::endl;
                        //v_obt.clear();
                        v_obt.push_back(v_obt.at(a)+1);
                        sizela++;
                        v_case_possible.erase(v_case_possible.begin()+b);

                        v_obt_qzdqdz.push_back(2);
                        break;
                    }
                    else if(v_obt.at(a)-30==v_case_possible.at(b)){
                        v_test_nb_chemin.push_back(-30);
                       // v_obt.erase(v_obt.begin()+a);
                       // v_obt.push_back(v_restant.at(a)-30);
                        std::cout << v_obt.at(a)-30 << std::endl;
                        //v_obt.clear();
                        v_obt.push_back(v_obt.at(a)-30);
                        sizela++;
                        v_case_possible.erase(v_case_possible.begin()+b);

                        v_obt_qzdqdz.push_back(3);
                        break;
                    }
                    else if(v_obt.at(a)+30==v_case_possible.at(b)){
                        v_test_nb_chemin.push_back(30);
                       // v_obt.erase(v_obt.begin()+a);
                       // v_obt.push_back(v_restant.at(a)+30);
                        std::cout << v_obt.at(a)+30 << std::endl;
                        //v_obt.clear();
                        v_obt.push_back(v_obt.at(a)+30);
                        sizela++;
                        v_obt_qzdqdz.push_back(4);
                        v_case_possible.erase(v_case_possible.begin()+b);
                        break;
                    }
                }


            }

            std::cout << "----------------------------------------------------" << std::endl;

         /*   for(int a=0;a<v_restant.size();a++){

                for(int b=0;b<v_case_possible.size();b++){

                    if(v_restant.at(a)-1==v_case_possible.at(b)){
                        v_test_nb_chemin.push_back(-1);
                        v_test_chemin.push_back(v_restant.at(a)-1);
                        v_obt.push_back(v_restant.at(a)-1);
                    }
                    if(v_restant.at(a)+1==v_case_possible.at(b)){
                        v_test_nb_chemin.push_back(1);
                        v_test_chemin.push_back(v_restant.at(a)+1);
                        v_obt.push_back(v_restant.at(a)+1);
                    }
                    if(v_restant.at(a)-30==v_case_possible.at(b)){
                        v_test_nb_chemin.push_back(-30);
                        v_test_chemin.push_back(v_restant.at(a)-30);
                        v_obt.push_back(v_restant.at(a)-30);
                    }
                    if(v_restant.at(a)+30==v_case_possible.at(b)){
                        v_test_nb_chemin.push_back(30);
                        v_test_chemin.push_back(v_restant.at(a)+30);
                        v_obt.push_back(v_restant.at(a)+30);
                    }

                }*/

            /*   std::cout << "---------------------------" << std::endl;

                for(int a=0;a<v_test_nb_chemin.size();a++){
                    std::cout << v_test_nb_chemin.at(a) << " / " << v_test_chemin.at(a) << std::endl;
                }

                std::cout << "---------------------------" << std::endl;*/

             //   v_restant.erase(v_restant.begin()+a);

       //     }

         //   std::cout << "-FINNNNNNNNNN-" << std::endl;

            ///mettre le meilleur chemin

        }

    private:

        int case_depart=0;
        int case_arrive=0;
        int case_depart_=0;
        int case_arrive_=0;
        std::vector<int>v_case_possible;
        std::vector<int>v_meilleur_chemin;
        std::vector<int>v_meilleur_nb_chemin;
        std::vector<int>v_test_chemin;
        std::vector<int>v_test_nb_chemin;
        std::vector<int>v_restant;
        std::vector<int>v_obt;
        std::vector<int>v_obt_;
        std::vector<int>v_obt_qzdqdz;

};

#endif // PATHFINDING_H

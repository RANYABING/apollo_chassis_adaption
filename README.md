# apollo_chassis_adaption

***This project is used for adapting CAN communication of Baidu Apollo and vehicle chassis***  

【项目介绍】  

本项目是为记录apollo和车辆底盘适配过程所创建的。下面详细介绍项目内各部分内容：  

1、MJCar.dbc需要根据自己车辆的线控底盘情况设计，本项目控制四个模块：  

*线控油门  
*线控制动  
*线控转向  
*线控档位  

2、MJCar.yml文件是根据apollo官方示例修改的，此处是生成后自动填充的内容。  

3、output_MJCar是用Apollo官方的DBC生成工具得到的文件夹，目录下/proto有数据定义文件【mjcar.proto】、/vehicle/mjcar/下BUILD是bazel编译工具生成的编译依赖，mjcar_controller、mjcar_message_manager、mjcar_vehicle_factory三类是该车底盘与apollo通信的车辆适配代码，/protocol下是具体的can报文解析；  



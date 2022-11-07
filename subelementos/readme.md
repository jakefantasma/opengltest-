#Game

## implementaciones 
clases implemtadas en el header global para la gestion del proyecto

### spawner
clase base que contendra el metodo para ser dibujado en patalla, los objetos a mostrar en vista deberan deribar de esta clases 
- draw 
- getIdObj -> id to remove 

### mapa 
permite el uso de la clases gl para la gestion de un mapa 2d, cuenta con dos metodos los cuales agregan o eliminan elemntos del mapa, ya que es un arreglo a los punteros objeto de spawn 

- spawn 
- remove

### keymove
un vector al cual podemos agregar las funciones a ejecutar


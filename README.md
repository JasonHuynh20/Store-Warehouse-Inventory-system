# Store-Warehouse-Inventory-system
Simplified inventory system for stores and warehouses which will automatically distribute the stock accordingly

Inventory system for a store / warehouse (like Ikea orCostco) using C++. This store will sell a number of Products. Each product has a StoreLocation. These locations are in the main store area where shoppers shop. Each product may have zero or more overstock locations in the warehouse. In the case of Ikea and Costco, the warehouse is in the same building as the main store. The products in the warehouse are stored on skids. Each skid consists of a single type of Product wrapped in plastic. The places where skids are stored will be called WHLocations (warehouse locations). Because WHLocations can only accept skids, they will be treated differently than StoreLocations, and will use inheritance to implement to two different styles of Locations.

To help with inventory system I will use a few different collections. I will use the linked List , but with some modifications. 
I will also implement a Queue, which is a linked list but with different rules for adding and removing. 
I will also use primitive arrays.





Since these are warehouse locations they only accept complete skids. So we can only add product if the location isAvailable, and if it will fit (i.e., the capacity is sufficient). In which case we set the product member variable to the product specified and the quantity to the quantity specified.
If the location is not empty, even if we are attempting to add the same product, do not change any values
and return false

when getting product from the warehouse locations ,subtract amount from the WHLocations in the Queue starting with the first, the proceeding to the second, etc. If a WHLocation becomes empty delete it from the Queue and move to the next. If all WHLocations become empty, return the amount you were unable to subtract.

When filling an order, remove amount of product from the store, starting with the StoreLocation and then, if there is still more amount left, move to the WHLocations. If no stock is left, return the amount of the order left to fill.

Sometimes when filling an order the StoreLocation becomes empty. then, add product to the StoreLocation until it is full (or you run out of product) by removing the same amount of product from the WHLocations. If the WHLocations become empty return from the function


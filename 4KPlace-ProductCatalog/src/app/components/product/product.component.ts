import { Component, Input } from '@angular/core';
import { ProductInterface } from 'src/app/product-interface';

@Component({
  selector: 'app-product',
  templateUrl: './product.component.html',
  styleUrls: ['./product.component.css']
})
export class ProductComponent {
  //title = 'Product Component Title'
  @Input() product: ProductInterface;

  constructor() { }

  onClick() { 
    console.log("FavoriteKK")
  }


}

import { Component, OnInit } from '@angular/core';
// import { FakeData } from 'src/app/fake-data';
import { ProductInterface } from 'src/app/product-interface';
import { ProductService } from 'src/app/services/product.service';

@Component({
  selector: 'app-products',
  templateUrl: './products.component.html',
  styleUrls: ['./products.component.css']
})
export class ProductsComponent {
  products: ProductInterface[] = [];

  constructor(private productService: ProductService) { }

  ngOnInit(): void {
    this.productService.getProducts().subscribe(products => this.products = products)
  }

}

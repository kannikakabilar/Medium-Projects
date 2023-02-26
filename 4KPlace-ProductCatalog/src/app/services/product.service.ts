import { Injectable } from '@angular/core';
import { FakeData } from '../fake-data';
import { ProductInterface } from '../product-interface';
import { Observable, of } from 'rxjs';
import { HttpClient, HttpHeaders } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class ProductService {

  private url = "https://63ed7947e6ee53bbf5960755.mockapi.io/products";

  constructor() { }

  getProducts(): Observable<ProductInterface[]> {
    const products = of(FakeData);
    return products;
  }
}

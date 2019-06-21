let toString = React.string;

module GetProducts = [%graphql
  {|
    query getProducts {
        products {
        id
          title
          offers {
            id
            reseller
            price
          }
        }
    }
  |}
];

module GetProductsQuery = ReasonApollo.CreateQuery(GetProducts);

[@react.component]
let make = () =>
  <GetProductsQuery>
    ...{({result}) =>
      <div>
        <h1> {"Products: " |> toString} </h1>
        {switch (result) {
         | Loading => "Loading..." |> toString
         | Error(e) => "Error :( " ++ e##message |> toString
         | Data(response) =>
           <ul>
             {response##products
              |> Array.map(product =>
                   <li key={product##id |> Js.Int.toString}>
                     <h3> {product##title |> toString} </h3>
                     <Offers offers=product##offers />
                     <Form productId=product##id />
                   </li>
                 )
              |> React.array}
           </ul>
         }}
      </div>
    }
  </GetProductsQuery>;
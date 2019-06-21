let toString = React.string;

module AddProductOffer = [%graphql
  {|
     mutation addProductOffer($productId: Int!, $reseller: String!, $price: String!) {
        addProductOffer(productId: $productId, reseller: $reseller, price: $price) {
            productId
            reseller
            price
        }
    }
  |}
];

module AddProductOfferMutation = ReasonApollo.CreateMutation(AddProductOffer);

[@react.component]
let make = (~productId) => {
  let (reseller, setReseller) = React.useState(() => "");
  let (price, setPrice) = React.useState(() => "");

  let addProductOffer =
    AddProductOffer.make(~productId, ~reseller, ~price, ());
  <AddProductOfferMutation>
    ...{(mutation, {result}) =>
      <div>
        <input
          onChange={e => e->ReactEvent.Form.target##value |> setReseller}
          id="reseller"
          type_="text"
          placeholder="Enter the reseller"
          value=reseller
        />
        <input
          onChange={e => e->ReactEvent.Form.target##value |> setPrice}
          id="price"
          type_="text"
          placeholder="Enter the price"
          value=price
        />
        <button
          onClick={_ =>
            mutation(
              ~variables=addProductOffer##variables,
              ~refetchQueries=[|"getProducts"|],
              (),
            )
            |> ignore
          }>
          {"Add offer" |> toString}
        </button>
        <span>
          {switch (result) {
           | NotCalled => "" |> toString
           | Loading => "Loading..." |> toString
           | Error(e) => "Error :( " ++ e##message |> toString
           | Data(_) => "Added!" |> toString
           }}
        </span>
      </div>
    }
  </AddProductOfferMutation>;
};
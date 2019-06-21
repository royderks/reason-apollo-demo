let toString = React.string;

[@react.component]
let make = (~offers) =>
  <ul>
    {offers
     |> Array.map(offer =>
          <li key={offer##id |> Js.Int.toString}>
            {offer##reseller |> toString}
            <span> {" - $ " |> toString} {offer##price |> toString} </span>
          </li>
        )
     |> React.array}
  </ul>;
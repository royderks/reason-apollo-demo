/* 
    This is where you set Reason to render the <App /> component within the ReasonApollo Provider, so it can use the reason-apollo GraphQL client to consume your GraphQL server 
*/
ReactDOMRe.renderToElementWithId(
  <ReasonApollo.Provider client=Client.instance>
    <App />
  </ReasonApollo.Provider>,
  "index",
);
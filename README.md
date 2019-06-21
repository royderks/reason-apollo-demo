# reason-apollo-demo

This demo shows how to consume data from a GraphQL Server with ReasonML 🚀.

## Getting Started

Open [this](https://codesandbox.io/s/50m91p16rp) CodeSandbox containing the GraphQL server and wait untill it's initialised (or use this url). You can now open the GraphQL playground in the browser tab on the right and inspect the server. **This server needs to run in order for the demo to work!**.

Clone this repository and from the root directory run the command:

```sh
yarn
```

This will install the dependencies needed to run this project. After the installation is complete you need to run the following command that introspects the GraphQL server, to make sure your Reason types match the schema:

```sh
yarn send-introspection-query https://50m91p16rp.sse.codesandbox.io/
```

### Run Project

```sh
yarn
yarn start
# in another tab
yarn server
```

View in the browser at http://localhost:8000. Running in this environment provides hot reloading; just edit and save the file and the browser will automatically refresh.

## Use Your Own GraphQL Server
In order to use your own GraphQL server for this demo, you'd need to change the definition of the GraphQL server in `src/Client.re` to:

```
/* Create an HTTP Link */
let httpLink =
  ApolloLinks.createHttpLink(~uri="GRAPHQL_SERVER_URL", ());
```

Also, you should introspect this GraphQL server to make sure the Reason types will match the schema:

```sh
yarn send-introspection-query GRAPHQL_SERVER_URL
```

*If your GraphQL server will have a different schema than the example server, everything will break! But you should be getting pointers from BuckleScript in the terminal to help you fix any compile errors.*
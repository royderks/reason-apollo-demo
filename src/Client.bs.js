// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var ApolloLinks = require("reason-apollo/src/ApolloLinks.bs.js");
var ReasonApollo = require("reason-apollo/src/ReasonApollo.bs.js");
var ApolloInMemoryCache = require("reason-apollo/src/ApolloInMemoryCache.bs.js");

var inMemoryCache = ApolloInMemoryCache.createInMemoryCache(undefined, undefined, /* () */0);

var httpLink = ApolloLinks.createHttpLink("https://50m91p16rp.sse.codesandbox.io/", undefined, undefined, undefined, undefined, undefined, /* () */0);

var instance = ReasonApollo.createApolloClient(httpLink, inMemoryCache, undefined, undefined, undefined, undefined, /* () */0);

exports.inMemoryCache = inMemoryCache;
exports.httpLink = httpLink;
exports.instance = instance;
/* inMemoryCache Not a pure module */

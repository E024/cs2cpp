﻿namespace Il2Native.Logic.Gencode.InternalMethods.RuntimeTypeHandler
{
    using System;
    using System.Collections.Generic;

    using PEAssemblyReader;

    public static class GetBaseTypeGen
    {
        public static readonly string Name = "System.RuntimeType System.RuntimeTypeHandle.GetBaseType(System.RuntimeType)";

        public static IEnumerable<Tuple<string, Func<IMethod, IMethod>>> Generate(ICodeWriter codeWriter)
        {
            var ilCodeBuilder = new IlCodeBuilder();
            ilCodeBuilder.LoadArgument(0);
            ilCodeBuilder.LoadField(OpCodeExtensions.GetFieldByName(codeWriter.System.System_RuntimeType, RuntimeTypeInfoGen.BaseTypeField, codeWriter));
            ilCodeBuilder.Add(Code.Ret);

            ilCodeBuilder.Parameters.Add(codeWriter.System.System_RuntimeType.ToParameter("type"));

            yield return ilCodeBuilder.Register(Name, codeWriter);
        }
    }
}
